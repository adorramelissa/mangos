#! /usr/bin/perl
package PerlACE::TestTarget_VxWorks;

# ******************************************************************
# Description : Creates a PerlACE::ProcessVX
# Author      : Chad Elliott
# Create Date : 6/20/2008
#          $Id: TestTarget_VxWorks.pm 82661 2008-08-28 13:06:04Z johnnyw $
# ******************************************************************

# ******************************************************************
# Pragma Section
# ******************************************************************

use strict;

use PerlACE::TestTarget;
use PerlACE::ProcessVX;

our @ISA = qw(PerlACE::TestTarget);

# ******************************************************************
# Subroutine Section
# ******************************************************************

sub LocalFile {
  my($self, $file) = @_;
  print STDERR "LocalFile for $file is $file\n";
  return $file;
}

sub CreateProcess {
  my $self = shift;
  return new PerlACE::ProcessVX(@_);
}

# Need a reboot when this target is destroyed.
sub NeedReboot ($)
{
    my $self = shift;
    $self->{REBOOT_NEEDED} = 1;
}

# Reboot target
sub RebootNow ($)
{
    my $self = shift;
    $self->{REBOOT_NEEDED} = undef;
    print STDERR "Attempting to reboot target...\n";
    reboot ();
}


1;
