name = 1 population = 2
cities = [
["Lagos", 21] , 
["Cairo", 15.2], 
["Kinshasa-Brazzaville", 11.3], 
["Greater Johannesburg",  7.55], 
["Mogadishu", 5.85], 
["Khartoum-Omdurman",  4.98], 
["Dar Es Salaam",  4.7], 
["Alexandria", 4.58], 
["Abidjan",  4.4], 
["Casablanca",  3.98 ]
]
See find(cities,"Dar Es Salaam",name) + nl   # output = 7
See cities[find(cities,4.58,population)][name] + nl   # output = Alexandria
for x in cities if x[population] < 5  see x[name] + nl exit ok next