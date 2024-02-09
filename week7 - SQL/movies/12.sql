SELECT DISTINCT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE movies.id IN ( SELECT movie_id FROM stars WHERE stars.person_id IN 
(SELECT id FROM people WHERE name = "Bradley Cooper"))
AND
movies.id IN (SELECT movie_id FROM stars WHERE stars.person_id IN 
(SELECT id FROM people WHERE name = "Jennifer Lawrence"))
;
