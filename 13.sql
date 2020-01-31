/*List the names of all people who starred in a movie in which Kevin Bacon also starred*/
SELECT name
FROM people
WHERE people.id IN (SELECT DISTINCT stars.person_id
    FROM stars
    JOIN people ON people.id = stars.person_id
    WHERE stars.movie_id IN (SELECT movies.id
        FROM movies
        JOIN stars ON stars.movie_id = movies.id
        JOIN people ON people.id = stars.person_id
        WHERE name = 'Kevin Bacon'
        AND birth = 1958)
        AND name <> 'Kevin Bacon');