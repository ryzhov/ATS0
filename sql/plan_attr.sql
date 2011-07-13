CREATE TABLE plan_attr (
    id		INTEGER REFERENCES plans(id),
    dir		VARCHAR(13) REFERENCES direction(dir),
    valid	TIMESTAMP WITHOUT TIME ZONE DEFAULT '1970-01-01 00:00:00',
    cost	NUMERIC(9,6) DEFAULT 0,
    
    PRIMARY KEY (id, dir, valid)

);
