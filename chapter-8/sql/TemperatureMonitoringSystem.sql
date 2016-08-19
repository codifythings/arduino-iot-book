CREATE TABLE `TEMPERATURE_MONITORING_DATA`
(
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `TIMESTAMP` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `TEMPERATURE` double NOT NULL,
  PRIMARY KEY (`ID`)
)
