CREATE TABLE customer_plan (
    customer_id		integer REFERENCES customer(id),
    plan_id		integer REFERENCES plans(id),

    PRIMARY KEY(customer_id,plan_id)
);
