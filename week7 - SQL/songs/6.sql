SELECT name FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE id = 54);

