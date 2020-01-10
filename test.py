import cs50
import csv

#with open('names.csv', 'w') as csvfile:

#    fieldnames = ['names', 'houses', 'roles']
#    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
#    reader = csv.DictReader(csvfile)
#    for row in reader:
#        print(row)

names = []
houses = []
roles = []

with open('survey.csv', newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    rowcount = 0

    for row in reader:
        names.append(row['name'])
        houses.append(row['house'])
        roles.append(row['role'])
        rowcount = rowcount + 1
    print(type(names))