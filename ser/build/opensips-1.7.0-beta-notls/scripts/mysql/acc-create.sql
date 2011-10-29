INSERT INTO version (table_name, table_version) values ('acc','6');
CREATE TABLE acc (
    id INT(10) UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    method CHAR(16) DEFAULT '' NOT NULL,
    from_tag CHAR(64) DEFAULT '' NOT NULL,
    to_tag CHAR(64) DEFAULT '' NOT NULL,
    callid CHAR(64) DEFAULT '' NOT NULL,
    sip_code CHAR(3) DEFAULT '' NOT NULL,
    sip_reason CHAR(32) DEFAULT '' NOT NULL,
    time DATETIME NOT NULL,
    duration INT(11) UNSIGNED DEFAULT 0 NOT NULL,
    setuptime INT(11) UNSIGNED DEFAULT 0 NOT NULL,
    created DATETIME NOT NULL
) ENGINE=MyISAM;

CREATE INDEX callid_idx ON acc (callid);

INSERT INTO version (table_name, table_version) values ('missed_calls','4');
CREATE TABLE missed_calls (
    id INT(10) UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    method CHAR(16) DEFAULT '' NOT NULL,
    from_tag CHAR(64) DEFAULT '' NOT NULL,
    to_tag CHAR(64) DEFAULT '' NOT NULL,
    callid CHAR(64) DEFAULT '' NOT NULL,
    sip_code CHAR(3) DEFAULT '' NOT NULL,
    sip_reason CHAR(32) DEFAULT '' NOT NULL,
    time DATETIME NOT NULL
) ENGINE=MyISAM;

CREATE INDEX callid_idx ON missed_calls (callid);

