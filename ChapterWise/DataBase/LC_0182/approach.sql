SELECT DISTINCT p1.email AS Email
FROM Person p1 
JOIN Person p2 ON p1.id != p2.id 
WHERE p1.email = p2.email;