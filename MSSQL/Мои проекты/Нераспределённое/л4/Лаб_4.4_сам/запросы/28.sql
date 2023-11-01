SELECT Kontinent
FROM Tabl_Kontinent$
WHERE KolNas > 1000000
GROUP BY Kontinent
HAVING AVG(KolNas / PL) > 30;