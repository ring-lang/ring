create table if not exists "user"
(
	id          serial       primary key,
	first_name  varchar(130) not null,
	last_name   varchar(130) not null,
	address     varchar(250) not null,
	address2    varchar(250) not null,
	city        varchar(70)  not null,
	state       varchar(60)  not null,
	zip         varchar(5)   not null,
	email       varchar(254) not null unique,
	username    varchar(150) not null unique,
	password    varchar(150) not null,
	date_joined timestamp    with time zone not null,
	last_login  timestamp    with time zone,
	is_admin    boolean      not null,
	is_active   boolean      not null
);

create table if not exists product
(
	id           serial primary key,
	name         varchar(255) not null,
	description  varchar(500) not null,
	price        numeric(6,2) not null,
	is_active    boolean      not null,
	publish_date timestamp    with time zone not null
);

create table if not exists user_product_favorites
(
	user_id    integer not null,
	product_id integer not null,
	primary key(user_id, product_id),
	foreign key(user_id)    references "user"(id),
	foreign key(product_id) references product(id)
);

create table IF NOT EXISTS "order"
(
	id          serial    primary key,
	order_date  timestamp with time zone not null,
	is_finished boolean   not null,
	user_id     integer   not null,
	foreign key(user_id)  references "user"(id)
);

create table if not exists order_details
(
	order_id   integer       not null,
	product_id integer       not null,
	quantity   integer       not null,
	price      numeric(6, 2) not null,
	primary key(order_id, product_id),
	foreign key(order_id)   references "order"(id),
	foreign key(product_id) references product(id)
);

create table if not exists payment
(
	id               serial       primary key,
	order_id         integer      unique,
	shipment_address varchar(250) not null,
	shipment_phone   varchar(50)  not null,
	card_number      varchar(25)  not null,
	expire           date         not null,
	security_code    varchar(4)   not null,
	foreign key(order_id) references "order"(id)
);

insert into product values(1, 'Caffè Americano', 'Caffè Americano is a type of coffee drink prepared by diluting an espresso with hot water, giving it a similar strength to, but different flavor from, traditionally brewed coffee.', 10, True, CURRENT_TIMESTAMP);
insert into product values(2, 'Café Latte', 'Café Latte is a coffee drink made with espresso and steamed milk.', 20, True, CURRENT_TIMESTAMP);
insert into product values(3, 'Cappuccino', 'Cappuccino  is an espresso-based coffee drink that originated in Italy, and is traditionally prepared with steamed milk foam (microfoam).', 30, True, CURRENT_TIMESTAMP);
insert into product values(4, 'Espresso', 'Espresso is a coffee-making method of Italian origin, in which a small amount of nearly boiling water is forced under pressure (expressed) through finely-ground coffee beans.', 35, True, CURRENT_TIMESTAMP);
insert into product values(5, 'Chocolate Coffee', 'Chocolate Coffee is a Coffee with small pieces of chocolate with high quality fresh milk.', 40, True, CURRENT_TIMESTAMP);
insert into product values(6, 'Arabica Coffee', 'Arabica is the most popular type of coffee, hands down. Depending on who you ask, many coffee enthusiasts prefer using Arabica beans due to its taste.', 37, True, CURRENT_TIMESTAMP);
insert into product values(7, 'Robusta Coffee', 'While Arabica is the most popular, Robusta is cheaper and stronger. Because of its bitter flavor, you’ll typically see Robusta used for espresso drinks and in instant coffee mixes.', 47, True, CURRENT_TIMESTAMP);
insert into product values(8, 'Black Coffee', 'Black coffee is as simple as it gets with ground coffee beans steeped in hot water, served warm.', 19, True, CURRENT_TIMESTAMP);
insert into product values(9, 'Doppio Coffee', 'A double shot of espresso, the doppio is perfect for putting extra pep in your step.', 50, True, CURRENT_TIMESTAMP);
insert into product values(10, 'Cortado Coffee', 'Like yin and yang, a cortado is the perfect balance of espresso and warm steamed milk.', 37, True, CURRENT_TIMESTAMP);
insert into product values(11, 'Red Eye Coffee', 'Named after those pesky midnight flights, a red eye can cure any tiresome morning. A full cup of hot coffee with an espresso shot mixed in, this will definitely get your heart racing.', 57, True, CURRENT_TIMESTAMP);
insert into product values(12,'Galão Coffee', 'Originating in Portugal, this hot coffee drink is closely related to the latte and cappuccino. Only difference is it contains about twice as much foamed milk, making it a lighter drink compared to the other two.', 37, True, CURRENT_TIMESTAMP);
insert into product values(13, 'Lungo Coffee', 'A lungo is a long-pull espresso. The longer the pull, the more caffeine there is and the more ounces you can enjoy.', 59, True, CURRENT_TIMESTAMP);
insert into product values(14, 'Macchiato Coffee', 'The macchiato is another espresso-based drink that has a small amount of foam on top. It’s the happy medium between a cappuccino and a doppio.', 35, True, CURRENT_TIMESTAMP);
insert into product values(15, 'Mocha Coffee', 'For all you chocolate lovers out there, you’ll fall in love with a mocha (or maybe you already have).', 60, True, CURRENT_TIMESTAMP);
insert into product values(16, 'Ristretto Coffee', 'Ristretto is an espresso shot. It uses less hot water which creates a sweeter flavor compared to the bitter taste of a traditional shot of espresso or a doppio.', 37, True, CURRENT_TIMESTAMP);
insert into product values(17, 'Flat White Coffee', 'This Aussie-born drink is basically a cappuccino without the foam or chocolate sprinkle. It’s an espresso drink with steamed milk.', 46, True, CURRENT_TIMESTAMP);
insert into product values(18, 'Affogato Coffee', 'The affogato is an excuse to enjoy a scoop of ice cream any time of day (and any time of year in my opinion).', 55, True, CURRENT_TIMESTAMP);
insert into product values(19, 'Irish Coffee', 'Irish coffee consists of black coffee, whiskey and sugar, topped with whipped cream.', 56, True, CURRENT_TIMESTAMP);
insert into product values(20, 'Iced Coffee', 'A coffee with ice, typically served with a dash of milk, cream or sweetener—iced coffee is really as simple as that.', 45, True, CURRENT_TIMESTAMP);
insert into product values(21, 'Coffee with Vanilla', 'Coffee with vanilla and ice, typically served with a dash of milk, cream or sweetener—iced coffee is really as simple as that, all this with a wonderful vanilla taste.', 37, True, CURRENT_TIMESTAMP);