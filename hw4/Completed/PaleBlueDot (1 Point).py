import datetime
import urllib.request
import math
import json

# These imports may be helpful. Feel free to add more if needed


# Location class used to communicate lat/long
class Location:
    # Do not put member variable outside the constructor
    # Variables declared here become static class variables

    # constructor in python. "self" is similar to "this" and must be the first parameter in every method declaration
    def __init__(self, latitude, longitude):
        # self variables declared in the constructor become member variables
        self.latitude = latitude
        self.longitude = longitude if longitude < 180.0 else longitude - 360.0

    def getLatitude(self):
        return self.latitude

    def getLongitude(self):
        return self.longitude

    def __str__(self):
        return "(" + str(self.latitude) + "," + str(self.longitude) + ")"


# The primary class that needs to be implemented. Some skeleton code has been provided, but is not necessary. Feel free
# to structure your code any way you want as long as the required methods function properly.
class PaleBlueDot:
    # Do not put member variable outside the constructor
    # Variables declared here become static class variables

    # Parse files and initialize all data structures. The citiesFile is in the format of worldCities.csv
    def __init__(self, citiesFile):
        self.cityLocations = {}  # initialize a dictionary. You can use any data structure you choose
        self.observatories = {}  # initialize a dictionary*. You can use any data structure you choose
        self.parseCities(citiesFile)
        self.getObservatories()

    def parseCities(self, citiesFile):
        cities = open(citiesFile, "r")  # open a file in read mode
        cities.readline()  # remove source
        cities.readline()  # remove header

        for line in cities.readlines():
            # Country,City,Region,Latitude,Longitude
            # TODO

            elements = line.split(",")

            # ['country','city','region'] = elements[0:2]
            # ['latitude','longitude'] = (elements[3:4])

            locationName = (str(elements[1]), str(elements[2]), str(elements[0]))

            self.cityLocations[locationName] = Location(float(elements[3]), float(elements[4]))
            pass

        cities.close()



    # pull observatory information from the Internet, parse and store.
    def getObservatories(self):
        url = "http://www.minorplanetcenter.net/iau/lists/ObsCodes.html"
        # Open the url in a browser to see the format of the data.
        result = urllib.request.urlopen(url)  # download the data
        observatories = result.read().decode('utf-8')  # read the data as unicode

        for line in observatories.split("\n"):
            # TODO

            if line[0:4] == "Code" or line[0:3] == "<pr" or line[0:3] == "</p":
                continue

            if line[0:3] == "244" or line[0:3] == "245" or line[0:3] == "247" or line[0:3] == "248" or line[0:3] == "249" or line[0:3] == "250":
                continue

            if line[0:3] == "C48" or line[0:3] == "C49" or line[0:3] == "C50" or line[0:3] == "C51" or line[0:3] == "C52" or line[0:3] == "C53":
                continue

            code = line[0:3].strip()
            long = line[4:13].strip()
            cos = line[14:21].strip()
            sin = line[21:30].strip()
            name = line[30:].strip()

            self.observatories[code] = name

            pass

    # part 1 - String Parsing

    '''
    Given the name a city, its region, and country, returns its location as a Location object. Returns an empty list
    if the city is unknown, though bad inputs will not be tested for grading so an error can be thrown instead.
    '''

    def getCityLocation(self, city, region, country):
        locations = (str(city),str(region),str(country))
        return self.cityLocations[locations]


    '''
    Given a 3 digit observatory code as a string, return the name of the corresponding observatory.

    Current data can be found here: http://www.minorplanetcenter.net/iau/lists/ObsCodes.html

    Note that this data is not in the most friendly format and care must be taken while parsing. Non-existing codes
    will not be tested.
    '''

    def getObservatoryName(self, observatoryCode):
        return self.observatories[observatoryCode]
        pass

    # part 2 - Math

    '''
    Given a 3 digit observatory code as a string, return the location of the corresponding observatory
    as a Location object with lat /long in degrees. Note that the data is given as
    longitude (in degrees), cos, and sin. Computing atan(sin/cos) will give the latitude in radians.
    Non-existing codes will not be tested.
    '''

    def getObservatoryLocation(self, observatoryCode):
        pass

    '''
    Return the great circle distance between two locations on Earth in kilometers. For information on great circle
    distance including sample code in JavaScript see: http://www.movable-type.co.uk/scripts/latlong.html
    '''

    def greatCircleDistance(self, location1, location2):
        pass

    # part 3

    '''
    Given a location on Earth by lat/long, return the code of the closest observatory in terms of
    great circle distance
    '''

    def getClosestObservatory(self, location):
        pass

    '''
    Return the code of the observatory that is closest to the ISS. ISS location can be obtained through
    this API: http://api.open-notify.org/
    The result will be in json form which python will parse using "json.loads(jsonData)"
    '''

    def getClosestObservatoryToISS(self):
        pass

    '''
    Return the next chance to observe the ISS from the given location. Use the same API from the previous
    method, but call "pass time" to retrieve the relevant data. Parsing the JSON will result in a unix
    timestamp that must be converted and returned in a user friendly format via:
    datetime.datetime.fromtimestamp(int("1457985637")).strftime('%Y-%m-%d %H:%M:%S')
    This is the format expected during testing.
    '''

    def nextPassTime(self, location):
        pass

    # part 4

    '''
    Given a location on Earth by lat/long, return the name of the closest city in terms of
    great circle distance. Credit will only be given if the efficiency bound is met. No
    partial credit for correctness. Return the city as a list in the form [city,region,countryCode]
    '''

    def getClosestCity(self, location):
        pass

    '''
    Return the closest city to the ISS. Return city as a list in the form [city,region,countryCode]
    '''

    def getClosestCityToISS(self):
        pass
