-- Keep a log of any SQL queries you execute as you solve the mystery.
.tables

SELECT * FROM crime_scene_reports;
-- theft of duck at 10:15am at humphrey street bakery
SELECT * from interviews where month = 7 AND day = 28 and year = 2024;

-- thief withrew money at ATM on leggett street earlier in morning
-- within 10 minutes of theft, car used by thief in parking lot
-- earliest flight out of fiftyville on the 29th, called someone to make the purchase, call was less than a minute
SELECT * FROM atm_transactions where year = 2024 and month = 7 and day = 28;
-- narrow down by atm_location
SELECT * FROM atm_transactions where year = 2024 and month = 7 and day = 28 and atm_location = 'Leggett Street';
-- SELECT a.*,c.name FROM atm_transactions a LEFT JOIN bank_accounts b ON b.account_number = a.account_number LEFT JOIN  where year = 2024 and month = 7 and day = 28 and atm_location = "Leggett Street" and transaction_type = 'withdraw';
-- names Luca, kenny, taylor, bruce, brooke, iman, benista, diana
.schema airports
.schema flights
.schema passengers

SELECT * FROM flights where month = 7 and day = 29 and year = 2024 and hour <= 12;
-- 3 flights, earliest is at 8:20am
SELECT * from flights LEFT JOIN airports ON airports.id = flights.destination_airport_id WHERE flights.id = 36 and year = 2024 and month = 7 and day = 29;
-- flight went to laguardia in NY
SELECT * FROM passengers where flight_id = 36;
SELECT * FROM passengers LEFT JOIN people on passengers.passport_number = people.passport_number where flight_id = 36;
-- ATM List : Luca, kenny, taylor, bruce, brooke, iman, benista, diana
-- flight list: Doris, Sofia, Bruce, Edward, Kelsey, Taylor, Kenny, Luca
-- in both: Luca, Kenny, Taylor, Bruce
SELECT * from phone_calls where year = 2024 and day = 28 and month = 7 and duration < 60;
SELECT * from phone_calls LEFT JOIN people on phone_calls.caller = people.phone_number where year = 2024 and day = 28 and month = 7 and duration < 60
-- callers with less than 60s call matching up with prior list: Taylor, Bruce, Kenny
SELECT * FROM bakery_security_logs where year = 2024 and month = 7 and day = 28 and hour = 10;
-- interview said within 10 minutes, and car theif got in left
SELECT * FROM bakery_security_logs LEFT JOIN people on people.license_plate = bakery_security_logs.license_plate where activity = 'exit' and year = 2024 and month = 7 and day = 28
 and hour = 10 and minute > 15;
 -- out of taylor bruce and kenny, the only one between 10:05 and 10:15 using the car was Bruce
 -- call bruce made receiver # is (375) 555-8161
 SELECT * from people where phone_number = '(375) 555-8161';
 -- bruce called robin






