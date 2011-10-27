CREATE FUNCTION getcostin(op integer, dd text, dur integer) RETURNS numeric
    LANGUAGE plpgsql
        AS $$
    DECLARE
	costIn	numeric(9,6);
	cost	numeric(9,4);
	d	text;
BEGIN
d:=dd;
WHILE length(d)>0 LOOP
	SELECT INTO costIn cost_in[1] FROM plan WHERE operator=op AND dir=d;
	IF FOUND THEN
	    cost=costIn*dur/60;
	    RETURN cost;
	END IF;
	d:=substr(d,1,length(d)-1);
END LOOP;
cost:=0;
RETURN cost;
END;
$$;		
