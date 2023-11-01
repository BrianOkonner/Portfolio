SELECT
  Kontinent,
  SUM(KolNas) * 1.1 AS PrognozNas
FROM
  Tabl_Kontinent$
GROUP BY
  Kontinent
