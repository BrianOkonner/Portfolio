SELECT
  Nazvanie
FROM
  Tabl_Kontinent$
WHERE
  KolNas = (
    SELECT
      MAX(KolNas)
    FROM
      Tabl_Kontinent$
  ) and( Kontinent='Северная Америка' or
	Kontinent='Южная Америка')