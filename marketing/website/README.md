Ring programming language - Website folder
==========================================

In this folder we have the Ring website files 
http://ring-lang.net

Please never modify the html files (*.html) directly because these files are generated
automatically from templates by the Ring script (build.ring)

To modify the data in the website just modify *.data files
To modify the representation/style just modify the *.template files

After modifying *.data or *.template run
ring build.ring to generate the HTML files 

Advantages
----------

* We upload static HTML files to the website (fast)
* The HTML files are generated from templates that includes Ring Code
* The Dynamic data are stored as lists in *.data files
* Header and Footer are added to all of the pages, we have header.template and footer.template
* Items count based on data in *.data files
* The first three news are added to the index page automatically
