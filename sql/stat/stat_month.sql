SELECT calldate,dst,(getDirX(dst)).dir as dir, (getDirX(dst)).dirName as dirName,
	billsec,getcostoutx(1,(getDirX(dst)).dir) as plan, 
	(getcostoutx(1,(getDirX(dst)).dir)*billsec/60)::numeric(10,6) as cost


FROM ast_cdr
WHERE 
	calldate >= date_trunc('month',current_date-interval '1 day') and
	calldate < current_date and
	src = '2332' and
	disposition = 'ANSWERED'

ORDER BY calldate ASC;
