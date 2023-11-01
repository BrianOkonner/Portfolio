SELECT
  AVG(LEN(Nazvanie)) AS AvgLength
FROM
  Tabl_Kontinent$
WHERE
  Kontinent = 'Африка';