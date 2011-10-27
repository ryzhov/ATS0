create or replace view customer_plans as
select  customer_plan.customer_id, customer.username, customer_plan.plan_id, 
	planss.name, planss.currency
FROM customer_plan
JOIN planss ON customer_plan.plan_id = planss.id
JOIN customer ON customer_plan.customer_id = customer.id
ORDER BY customer_plan.customer_id, planss.id;

