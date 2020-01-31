SELECT name
FROM people
WHERE people.id IN (SELECT DISTINCT stars.person_id
    FROM stars
    JOIN people ON stars.person_id = people.id
    WHERE stars.movie_id IN (SELECT movies.id
        FROM movies
        WHERE year = 2004))
ORDER BY birth;