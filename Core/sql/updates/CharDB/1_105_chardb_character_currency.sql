DROP TABLE IF EXISTS `character_currency`;
CREATE TABLE `character_currency` (
  `guid` INT(11) UNSIGNED NOT NULL,
  `currency` SMALLINT(5) UNSIGNED NOT NULL,
  `count` SMALLINT(5) UNSIGNED NOT NULL,
  `thisweek` SMALLINT(5) UNSIGNED NOT NULL,
  PRIMARY KEY (`guid`,`currency`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
