pdflatex -file-line-error -interaction=nonstopmode -output-directory out -synctex=1 -output-format=pdf thesis.tex
biber --input-directory out --output-directory out thesis
pdflatex -file-line-error -interaction=nonstopmode -output-directory out -synctex=1 -output-format=pdf thesis.tex