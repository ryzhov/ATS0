CREATE TABLE orders (
    id		INTEGER NOT NULL DEFAULT nextval('order_id_seq'::regclass),
    start_ts	TIMESTAMP WITHOUT TIME ZONE DEFAULT timezone('UTC'::text, now()),
    sender_ip	inet NOT NULL,
    username	VARCHAR(128) NOT NULL,
    content	TEXT NOT NULL,
    phone	VARCHAR(64) NOT NULL,
    
    PRIMARY KEY (id)

);
