# Edit the next line, adding space-separated base .tex file names...
BASENAMES=assignment1

LATEXMK=latexmk
LATEXMK_OPTS=-xelatex -bibtex -silent -outdir=build -auxdir=build \
 -interaction=batchmode -latexoption="-file-line-error -halt-on-error -shell-escape"

# "make" or "make all" rule tells make to generate all PDFs...
all: $(BASENAMES:=.pdf)

# "make clean" rule tells make what to remove to clean up things...
clean:
	$(LATEXMK) $(LATEXMK_OPTS) -C $(BASENAMES:=.tex)
	rm -rf build/ deps/

# The next line includes any deps/*.deps files if they exist...
$(foreach file,$(BASENAMES:=.tex),$(eval -include deps/$(file).deps))

# The next rule enables make to create the deps directory when needed...
deps/%.tex.deps:
	@if [ ! -e deps ]; then mkdir -p deps; fi
	@if [ ! -e $@ ]; then touch $@; fi

# The next rule tells make how to build the .tex file...
%.pdf: %.tex deps/%.tex.deps
	$(LATEXMK) $(LATEXMK_OPTS) -recorder -use-make -M -MP -MF deps/$<.deps
