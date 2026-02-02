# Makefile

CC      := cc
CFLAGS  := -std=c89 -O2
LDFLAGS :=

DOCDIR  := docs
OUTDIR  := out

# Each folder in docs is one HTML file in out
# So, docs/calisthenics/*.c -> out/calisthenics.html
# This collects all the folders directly inside docs
DOC_PROJECTS := $(shell find $(DOCDIR) -mindepth 1 -maxdepth 1 -type d -printf '%f\n')

# We construct the output HTML doc names
DOC_OUTPUTS := $(addprefix $(OUTDIR)/,$(addsuffix .html,$(DOC_PROJECTS)))

.PHONY: all docs clean list

all: docs

docs: $(DOC_OUTPUTS)

$(OUTDIR)/%.html:
	@mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $(OUTDIR)/$*.out $(DOCDIR)/$*/*.c $(LDFLAGS)
	./$(OUTDIR)/$*.out > $@
	rm -f $(OUTDIR)/$*.out

# This is there just to confirm the variables are good
list:
	@echo "Doc projects:"
	@printf "  %s\n" $(DOC_PROJECTS)
	@echo ""
	@echo "Doc outputs:"
	@printf "  %s\n" $(DOC_OUTPUTS)

clean:
	-rm -rf $(OUTDIR)
