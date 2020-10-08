#!/bin/sh

echo "Setting Apache configuration before running this app ...\n\n"

# include ring web app virtual host in the built-in apache2 configuration - Ubuntu
if [ -f /etc/apache2/apache2.conf ]
then
        echo "Setting configuration for built-in apache - Ubuntu.....\n"
        if [ -L /etc/apache2/sites-enabled/ringwebapp.local.conf ]
        then
                echo "Removing previously set 'ringwebapp.local.conf' config file...\n"
                sudo rm /etc/apache2/sites-enabled/ringwebapp.local.conf
        fi
        echo "Setting new 'ringwebapp.local.conf' config file...\n"
        sudo ln -s "$1/ringwebapp.local.conf" /etc/apache2/sites-enabled
fi

# include ring web app virtual host in the built-in apache2 configuration - Fedora
if [ -f /etc/httpd/conf/httpd.conf ]
then
        echo "Setting configuration for built-in apache - Fedora.....\n"
        if [ -L /etc/httpd/conf.d/ringwebapp.local.conf ]
        then
                echo "Removing previously set 'ringwebapp.local.conf' config file...\n"
                sudo rm /etc/httpd/conf.d/ringwebapp.local.conf
        fi
        echo "Setting new 'ringwebapp.local.conf' config file...\n"
        sudo ln -s "$1/ringwebapp.local.conf" /etc/httpd/conf.d
fi

# include ring web app virtual host in the built-in apache2 configuration - MacOSX
if [ -f /etc/apache2/httpd.conf ]
then
        echo "Setting configuration for built-in apache - MacOSX.....\n"
        CONF_STR= 'Include /private/etc/apache2/vhosts/*.conf'
        if grep -q "$CONF_STR" /etc/apache2/httpd.conf; then
                if grep -q "#$CONF_STR" /etc/apache2/httpd.conf; then
                        echo "Reactivate inactivated vhosts inclusion in apache httpd.conf file...\n"
                        sudo sed -i '' "s/#$CONF_STR/$CONF_STR/g" /etc/apache2/httpd.conf
                fi
        else
                echo "Activate vhosts inclusion in apache httpd.conf file...\n"
                sudo sh -c 'echo "$CONF_STR" >> /etc/apache2/httpd.conf'
        fi
        if [ ! -d /private/etc/apache2/vhosts ]
        then
                echo "Create vhosts directory...\n"
                mkdir /etc/apache2/vhosts
        fi
        if [ -L /private/etc/apache2/vhosts/ringwebapp.local.conf ]
        then
                echo "Removing previously set 'ringwebapp.local.conf' config file...\n"
                rm /private/etc/apache2/vhosts/ringwebapp.local.conf
        fi
        echo "Setting new 'ringwebapp.local.conf' config file...\n"
        ln -s "$1/ringwebapp.local.conf" /private/etc/apache2/vhosts
fi

# add ringwebapp.local to /etc/hosts file
if ! grep -q 'ringwebapp.local' /etc/hosts; then
        sudo sh -c "echo '127.0.0.1   ringwebapp.local www.ringwebapp.local' >> /etc/hosts"
fi

# restart apache2 service to activate our ring web app
if [ -f /etc/apache2/apache2.conf ]
then
        echo "Restarting apache2 service - Ubuntu...\n"
        sudo systemctl restart apache2
fi
if [ -f /etc/httpd/conf/httpd.conf ]
then
        echo "Reloading apache2 service - Fedora...\n"
        sudo systemctl reload httpd.service
fi
if [ -f /etc/apache2/httpd.conf ]
then
        echo "Restarting apache2 service - MacOSX...\n"
        sudo apachectl restart
fi

echo "Saving the path of the lastly set project folder\n"
echo "$2" > "$1/lastrundirpath.txt"

echo "Setting all '.ring' files to be executable in the project\n"
sudo find $2 -name "*.ring" -exec chmod 755 {} \;


echo '\n\n\nYou can run the app now\nPress enter to continue'
read enter

