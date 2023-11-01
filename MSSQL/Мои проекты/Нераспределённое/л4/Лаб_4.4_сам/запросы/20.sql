SELECT
  COUNT(*) as Kol
FROM
  Tabl_Kontinent$
WHERE
  RIGHT(Nazvanie, 2) = 'ан' AND RIGHT(Nazvanie, 4) != 'стан';