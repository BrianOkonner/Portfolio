SELECT
  Kontinent
FROM
  (SELECT
     Kontinent,
     MAX(PL) / MIN(PL) AS Raznica
   FROM
     Tabl_Kontinent$
   GROUP BY
     Kontinent) AS Subquery
WHERE
  Raznica <= 10000;