import argparse
import util
import sys

parser = argparse.ArgumentParser(description='Resource tool used to build smw_assets.dat', allow_abbrev=False)
parser.add_argument('-r', '--rom', nargs='?', metavar='ROM')
parser.add_argument('--extract-from-rom', '-e', action='store_true', help='Extract assets from the ROM')
parser.add_argument('--no-hash-check', '-f', action='store_true', help='Bypass the hash check (needed for Lunar Magic roms)')
parser.add_argument('--no-include-rom', dest='include_rom', action='store_false', help='Don''t include the ROM in the assets file for verification')

optional = parser.add_argument_group('Debug things')
optional.add_argument('--print-assets-header', action='store_true')

args = parser.parse_args()

ROM = util.load_rom(args.rom, disable_hash_check = args.no_hash_check)



import compile_resources
compile_resources.main(args)


