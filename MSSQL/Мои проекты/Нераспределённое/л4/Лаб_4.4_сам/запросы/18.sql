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
  ) and( Kontinent='�������� �������' or
	Kontinent='����� �������')