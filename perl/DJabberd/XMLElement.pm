package DJabberd::XMLElement;
use strict;
use fields (
            'ns',        # namespace name
            'element',   # element name
            'attrs',     # hashref of {namespace}attr => value.  NOTE: used by Stanza.pm directly.
            'children',  # arrayref of child elements of this same type, or scalars for text nodes
            'raw',       # in some cases we have the raw xml and we have to create a fake XMLElement object
                         # business logic is that as_xml returns the raw stuff if it is exists, children has to be empty -- sky
            );

use DJabberd::Util;

sub new {
    my $class = shift;
    if (ref $_[0]) {
        # the down-classer that subclasses can inherit
        return bless $_[0], $class;
    }

    # constructing a new XMLElement:
    my DJabberd::XMLElement $self = fields::new($class);
    ($self->{ns},
     $self->{element},
     $self->{attrs},
     $self->{children}) = @_;
    #my ($ns, $elementname, $attrs, $children) = @_;
    #Carp::confess("children isn't an arrayref, is: $children") unless ref $children eq "ARRAY";

    #DJabberd->track_new_obj($self);
    return $self;
}

#sub DESTROY {
#    my $self = shift;
#    DJabberd->track_destroyed_obj($self);
#}

sub push_child {
    my DJabberd::XMLElement $self = $_[0];
    push @{$self->{children}}, $_[1]; # $node
}

sub set_raw {
    my DJabberd::XMLElement $self = shift;
    $self->{raw} = shift;
    $self->{children} = [];
}

sub children_elements {
    my DJabberd::XMLElement $self = $_[0];
    return grep { ref $_ } @{ $self->{children} };
}

sub remove_child {
    my DJabberd::XMLElement $self = $_[0];
    @{$self->{children}} = grep { $_ != $_[1] } @{$self->{children}};
}

sub replace_child {
    my DJabberd::XMLElement $self = $_[0];
    my $to_replace=$_[1];
    my $with=$_[2];
    my $found=0;
    map { if ($_ == $to_replace) { $_=$with; $found=1; } } @{$self->{children}};
    $self->push_child($with) unless ($found);
}

sub children {
    my DJabberd::XMLElement $self = $_[0];
    return @{ $self->{children} };
}

sub first_child {
    my DJabberd::XMLElement $self = $_[0];
    return @{ $self->{children} } ? $self->{children}[0] : undef;
}

sub first_element {
    my DJabberd::XMLElement $self = $_[0];
    foreach my $c (@{ $self->{children} }) {
        return $c if ref $c;
    }
    return undef;
}

sub inner_ns {
    return $_[0]->{attrs}{'{}xmlns'};
}

sub attr {
    return $_[0]->{attrs}{$_[1]};
}

sub set_attr {
    $_[0]->{attrs}{$_[1]} = $_[2];
}

sub attrs {
    return $_[0]->{attrs};
}

sub element {
    my DJabberd::XMLElement $self = $_[0];
    return ($self->{ns}, $self->{element}) if wantarray;
    return "{$self->{ns}}$self->{element}";
}

sub element_name {
    my DJabberd::XMLElement $self = $_[0];
    return $self->{element};
}

sub namespace {
    my DJabberd::XMLElement $self = $_[0];
    return $self->{ns};
}

sub as_xml {
    my DJabberd::XMLElement $self = shift;
    my $nsmap = shift || {};  # localname -> uri, uri -> localname
    my $def_ns = shift;

    my ($ns, $el) = ($self->{ns}, $self->{element});

    my $attr_str = "";
    my $attr = $self->{attrs};
    foreach my $k (sort keys %$attr) {
        next if $k eq "{}xmlns";
        my $value = $attr->{$k};
        # FIXME: ignoring all namespaces on attributes
        $k =~ s!^\{(.*)\}!!;
        my $ns = $1;
        $attr_str .= " $k='" . DJabberd::Util::exml($value) . "'";
    }

    my $xmlns = (!$ns ||
                 ($def_ns && $ns eq $def_ns) ||
                 $ns eq "jabber:server" ||
                 $ns eq "jabber:component:accept" ||
                 $ns eq "jabber:client") ?
                 "" : " xmlns='$ns'";
    my $innards = $self->innards_as_xml($nsmap, $ns, $def_ns);
    $innards = "..." if $DJabberd::ASXML_NO_INNARDS && $innards;
    return length $innards ?
        "<$el$xmlns$attr_str>$innards</$el>" :
        "<$el$xmlns$attr_str/>";
}

sub innards_as_xml {
    my DJabberd::XMLElement $self = shift;
    my $nsmap = shift || {};
    my $def_ns = shift;

    if ($self->{raw}) {
        return $self->{raw};
    }

    my $ret = "";
    foreach my $c (@{ $self->{children} }) {
        if (ref $c) {
            $ret .= $c->as_xml($nsmap, $def_ns);
        } else {
            if ($DJabberd::ASXML_NO_TEXT) {
                $ret .= "...";
            } else {
                $ret .= DJabberd::Util::exml($c);
            }
        }
    }
    return $ret;
}

sub text {
    my $self=shift;
    die "text called on element with children" if ($self->first_element);
    my $ret="";
    foreach my $c ( @{$self->{children}} ) {
	$ret .= $c;
    }
    return $ret;
}

sub clone {
    my $self = shift;
    my $clone = fields::new(ref($self));
    $clone->{ns}       = $self->{ns};
    $clone->{element}  = $self->{element};
    $clone->{attrs}    = { %{ $self->{attrs} } };
    $clone->{children} = [ map { ref($_) ? $_->clone : $_ } @{ $self->{children} } ];
    $clone->{raw}      = $self->{raw};
    return $clone;
}

1;
