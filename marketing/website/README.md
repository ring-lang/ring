# Ring programming language - Website folder

In this folder we have the Ring website files
http://ring-lang.net

Please never modify the html files directly because these files are generated
automatically from templates using a simple Ring program

To modify the data in the website just modify the data files in the source/data folder

To modify the representation/style just modify the template files in the source/template folder

After modifying data/template files run the source/build.bat file
to generate the HTML files (This will run source/build.ring)

## Advantages

* We upload static HTML files to the website (fast)
* The HTML files are generated from templates that includes Ring Code
* The Dynamic data are stored as lists in data files
* Header and Footer are added to all of the pages
* Items count based on lists in data files
* The first three news are added to the index page automatically
