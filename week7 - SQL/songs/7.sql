SELECT AVG(energy) AS Avarage  FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE id =23);
