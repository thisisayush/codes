import json, os, time

while(1):
    os.system("clear")
    try:
        f = open(os.path.abspath(os.getcwd())+'/movies.json', 'r')
        data = f.read()
        f.close()
    except Exception as e:
       print("Error: "+e.message)
    movies = []
    try:
        movies = json.loads(data)
    except Exception as e:
       print("JSON Error: "+e.message)
    print("Movies Indexed: "+str(len(movies)))
    time.sleep(3)
