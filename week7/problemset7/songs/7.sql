SELECT AVG(energy)
FROM songs
where artist_id = (Select id FROM artists where name = 'Drake')
