SELECT
  COUNT(*) as Kol
FROM
  Tabl_Kontinent$
WHERE
  RIGHT(Nazvanie, 2) = '��' AND RIGHT(Nazvanie, 4) != '����';