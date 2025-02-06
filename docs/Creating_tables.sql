drop database StokiFy; # Reset values  
create database StokiFy;
use StokiFy;

CREATE TABLE `client` (
  `client_id` int PRIMARY KEY AUTO_INCREMENt,
  `client_name` varchar(100) NOT NULL,
  `client_description` varchar(200),
  `is_seller` bool DEFAULT false,
  `client_email` varchar(50) UNIQUE NOT NULL,
  `client_password` varchar(255) NOT NULL
)AUTO_INCREMENT 1000;

CREATE TABLE `item` (
  `item_id` int PRIMARY KEY AUTO_INCREMENT,
  `item_name` varchar(100) NOT NULL,
  `item_description` varchar(200),
  `item_price` decimal(10,2) NOT NULL,
  `seller_id` int NOT NULL
)AUTO_INCREMENT 1000;

CREATE TABLE `purchase` (
  `purchase_id` int PRIMARY KEY AUTO_INCREMENT,
  `selled_item_id` int NOT NULL,
  `seller_id` int NOT NULL,
  `buyer_id` int NOT NULL
)AUTO_INCREMENT 1000;

ALTER TABLE `item` ADD FOREIGN KEY (`seller_id`) REFERENCES `client` (`client_id`);

ALTER TABLE `item` ADD FOREIGN KEY (`item_id`) REFERENCES `purchase` (`purchase_id`);

ALTER TABLE `purchase` ADD FOREIGN KEY (`seller_id`) REFERENCES `client` (`client_id`);

ALTER TABLE `purchase` ADD FOREIGN KEY (`buyer_id`) REFERENCES `client` (`client_id`);

ALTER TABLE `purchase` ADD FOREIGN KEY (`selled_item_id`) REFERENCES `item` (`item_id`);


SHOW TABLES
