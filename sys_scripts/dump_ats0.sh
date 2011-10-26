#!/bin/bash

pg_dump --create --username=postgres ats0 | bzip2 -v > ats0.sql.bz2
tar cvjf ats0.html.tbz2 /var/www/html/ats0
tar cvjf uiptel.html.tbz2 /var/www/html/uiptel
scp ats0.sql.bz2 ran@cin:~/ATS0/
scp ats0.html.tbz2 ran@cin:~/ATS0/
scp uiptel.html.tbz2 ran@cin:~/ATS0/
