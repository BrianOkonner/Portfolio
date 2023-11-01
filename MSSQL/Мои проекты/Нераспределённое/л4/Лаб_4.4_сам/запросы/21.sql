SELECT
  COUNT(DISTINCT Kontinent) as Kol
FROM
  Tabl_Kontinent$
WHERE
  Nazvanie LIKE 'Ð%';