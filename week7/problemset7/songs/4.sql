-- list all where valence/energy/danceability > 0.75
SELECT name
FROM songs
where valence > 0.75 AND energy > 0.75 and danceability > 0.75;
