-- post malone id in artist table
SELECT name
FROM songs
where artist_id = (Select id FROM artists where name = 'Post Malone')
