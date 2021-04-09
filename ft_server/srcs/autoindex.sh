#!/bin/bash
if [ "$1" == "ON" ]; then 
	cp /tmp/nginx_config_on /etc/nginx/sites-available/default
	service nginx restart
elif [ "$1" == "OFF" ]; then 
	cp /tmp/nginx_config_off /etc/nginx/sites-available/default
	service nginx restart
fi
