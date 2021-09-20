pdflatex -file-line-error -interaction=nonstopmode -synctex=1 -output-format=pdf thesis.tex
biber thesis
pdflatex -file-line-error -interaction=nonstopmode -synctex=1 -output-format=pdf thesis.tex