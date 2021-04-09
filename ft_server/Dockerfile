FROM debian:buster

RUN apt-get update

RUN apt-get upgrade -y

RUN apt-get -y install wget

RUN apt-get -y install nginx

RUN apt-get -y install mariadb-server

RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

RUN apt-get -y install vim

WORKDIR /etc/nginx/

RUN mkdir ssl

WORKDIR /etc/nginx/sites-available/

RUN rm default

COPY ./srcs/nginx_config_on default

WORKDIR /var/www/html/

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz

RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz

RUN mv phpMyAdmin-5.0.1-english phpmyadmin

COPY ./srcs/config.inc.php ./phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz

RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

COPY ./srcs/wp-config.php /var/www/html

COPY ./srcs/nginx_config_off  /tmp/nginx_config_off

COPY ./srcs/nginx_config_on  /tmp/nginx_config_on 

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/nginx-selfsigned.pem -keyout /etc/nginx/ssl/nginx-selfsigned.key -subj "/C=FR/ST=Pasdris/L=Paris/O=42 School/OU=sfhds/CN=ninja_flex"

RUN chown -R www-data:www-data *

COPY ./srcs/autoindex.sh ./

RUN chmod -R 755 /var/www/*

COPY ./srcs/init.sh ./

CMD bash init.sh