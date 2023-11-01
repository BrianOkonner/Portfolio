SELECT
  LEN(Nazvanie) AS KolBuks,
  COUNT(*) AS Kol
FROM
  Tabl_Kontinent$
GROUP BY
  LEN(Nazvanie)
ORDER BY
  Kol DESC;