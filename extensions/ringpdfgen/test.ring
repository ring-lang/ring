load "pdfgen.ring"

info = pdf_info([
		:creator  = "My software",
		:producer = "My software",
		:title    = "My document",
		:author   = "My name",
		:subject  = "My subject",
		:date     = "Today"
	])

pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, varptr(:info,"struct pdf_info") )
pdf_set_font(pdf, "Times-Roman")
pdf_append_page(pdf)

pdf_add_text(pdf, NULL, "This is text", 12, 50, 20, PDF_BLACK)
pdf_add_line(pdf, NULL, 50, 24, 150, 24, 0, 0)
pdf_add_text(pdf, NULL, "This is text", 24, 250, 20, PDF_BLUE)

for t=1 to 30
	pdf_add_text(pdf, NULL, "Number: " + t, 14, 250, 50+(20*t), PDF_RED)
next

pdf_add_text(pdf, NULL, "I LOVE PROGRAMMING!", 48, 30, 700,PDF_BLUE)

pdf_save(pdf, "output.pdf")
pdf_destroy(pdf)

system("output.pdf")


