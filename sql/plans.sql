CREATE TABLE plans (
    id integer NOT NULL DEFAULT nextval('plan_id_seq'::regclass),
    name text NOT NULL,

    PRIMARY KEY(id)
);
