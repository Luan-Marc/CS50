-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Description Scene crime
SELECT description 
FROM crime_scene_reports 
WHERE month = 7 
AND day = 28 
AND street = "Humphrey Street";

-- Interviews

SELECT * FROM interviews 
WHERE transcript 
LIKE "%bakery%"
AND day = 28
AND month = 7;

-- Evidence 1 

SELECT name 
FROM people
WHERE license_plate IN (
SELECT license_plate 
FROM bakery_security_logs 
WHERE day = 28 
AND month = 7 
AND hour = 10 
AND minute >= 15
AND minute <= 25
AND activity = "exit"
);

--Evidence 2 

SELECT * 
FROM bank_accounts 
JOIN people 
ON bank_accounts.person_id = people.id 
WHERE bank_accounts.account_number IN (
SELECT account_number 
FROM atm_transactions 
WHERE atm_location 
LIKE "%Leggett%" 
AND day = 28 
AND month = 7 
AND transaction_type = "withdraw"
);

--Evidence 3 

SELECT *
FROM people
WHERE phone_number IN (
SELECT receiver 
FROM phone_calls 
WHERE day = 28 
AND year = 2021
AND month = 7 
AND duration <= 60
ORDER BY duration
);

--Evidence 4

SELECT * 
FROM flights 
WHERE day = 29 
AND origin_airport_id IN (
SELECT id
FROM airports 
WHERE full_name 
LIKE "%Fiftyville%"
)
ORDER BY hour ASC
LIMIT 1;

SELECT name 
FROM people
WHERE passport_number IN (
SELECT passport_number
FROM passengers 
WHERE flight_id = 36
);
