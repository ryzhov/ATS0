CREATE TABLE customer (
    id		integer NOT NULL DEFAULT nextval('customer_id_seq'::regclass),
    username	varchar(128) NOT NULL UNIQUE,
    credentials	integer NOT NULL DEFAULT 255,
    pass	varchar(40) NOT NULL,
    created	timestamp without time zone default timezone('UTC'::text, now()),
    last_login	timestamp without time zone,

    PRIMARY KEY(id)
);
