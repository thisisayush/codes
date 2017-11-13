from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors.sgml import SgmlLinkExtractor
import scrapy.selector
import os, json, requests
from urlparse import urljoin
import thread, threading
import lxml

class MoviesSpider(scrapy.Spider):
    name = "MoviesSpider"
    allowed_domains = ["www.imdb.com"]
    #start_url = ["http://www.imdb.com/chart/moviemeter"]
    start_url = ["http://www.imdb.com/year/"]
    movies = []

    #rules = [
    #    Rule(SgmlLinkExtractor(restrict_xpaths=("//td[contains(@class,'titleColumn')]/a")), callback='parseMovie')
    #]

    def start_requests(self):
        for u in self.start_url:
            yield scrapy.Request(url=u, callback=self.parse)

    def parse(self, response):
        hxs = scrapy.Selector(response)
        links = hxs.xpath("//table[contains(@class,'splash')]/tr/td/a/@href").extract()
        print("Found "+str(len(links))+" Years")
        for link in links:
            print(response.urljoin(link))
            yield scrapy.Request(url=response.urljoin(link), callback=self.parseResultPage)

    def parseResultPage(self,response):
        titles = response
        all_titles = titles.css('.lister-item')
        for title in all_titles:
            movie_name = title.xpath(".//h3[contains(@class,'lister-item-header')]/a/text()").extract_first()
            if movie_name == "None" or movie_name is None :
                continue
            movie_year = title.xpath(".//h3[contains(@class,'lister-item-header')]/span[2]/text()").extract_first()
            if movie_year is not None:
                movie_year = movie_year.replace("(","").replace(")","")
            movie_desc = title.xpath(".//div[3]/p[2]/text()").extract_first()
            if movie_desc is not None:
                movie_desc = movie_desc.replace("\n","\\n")
            movie_genre = title.xpath(".//div[3]/p[1]/span[contains(@class, 'genre')]/text()").extract_first()
            if movie_genre is not None:
                movie_genre = movie_genre.split(",")
            movie_rating = title.xpath(".//div[3]/div[1]//strong[1]/text()").extract_first()
            movie = {"title":movie_name, "description": movie_desc, "rating": movie_rating, "genre": movie_genre, "year": movie_year}
            yield self.writeToFile(movie)
            yield movie
            print("Finished Processing Movie:"+movie_name+" ("+movie_year+')')
        next_page = response.xpath("//a[contains(@class,'next-page')]/@href")
        next_url = response.urljoin(next_page.extract_first())
        if next_url is not None:
            #next_url = response.urljoin(next_page.extract_first())
            print(" ------------------- Moving to Next Page ("+next_url+") ---------------------")
            yield scrapy.Request(url = next_url, callback=self.parseResultPage)

    def writeToFile(self, movie):
        curr_dir = os.path.abspath(os.getcwd())
        data = open(curr_dir+"/movies.json","r")
        self.movies = []
        jsondata = data.read()
        try:
            self.movies = json.loads(jsondata)
        except ValueError as e:
            print("JSON READ ERROR "+e.message)
        if movie not in self.movies:
            print("Adding Movie to DB")
            self.movies.append(movie)
        data.close()
        dataToWrite = json.dumps(self.movies)
        data = open(curr_dir+"/movies.json","w")
        data.write(dataToWrite)
        data.close()

    def parseMovie(self, response):
        ''' This Fuction Parses individual Movie Page '''
        hxs = scrapy.Selector(response)
        title = hxs.xpath("//div[contains(@class,'title_wrapper')]/h1/text()").extract_first()
        description = hxs.xpath("//div[contains(@class,'summary_text')]/text()").extract_first()
        rating = hxs.xpath("//span[contains(@itemprop,'ratingValue')]/text()").extract_first()
        movie = {"title":title, "rating": rating, "description": description}
        curr_dir = os.path.abspath(os.getcwd())
        data = open(curr_dir+"/movies.json","r")
        self.movies = []
        jsondata = data.read()
        try:
            self.movies = json.loads(jsondata)
        except ValueError as e:
            print("JSON READ ERROR "+e.message)
        if title not in self.movies:
            print("Adding Movie to DB")
            self.movies.append(movie)
        data.close()
        dataToWrite = json.dumps(self.movies)
        #print(dataToWrite)
        data = open(curr_dir+"/movies.json","w")
        data.write(dataToWrite)
        data.close()