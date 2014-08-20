/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "precompile.hpp"
#include "command.hpp"

SX_USING_NAMESPACES()

BOOST_AUTO_TEST_SUITE(address_encode__invoke)

// vectors
#define SX_ADDRESS_ENCODE_RIPEMD160_A "b472a266d0bd89c13706a4132ccfb16f7c3b9fcb"

// expectations
#define SX_ADDRESS_ENCODE_ADDRESS_A_V0 "1HT7xU2Ngenf7D4yocz2SAcnNLW7rK8d4E"
#define SX_ADDRESS_ENCODE_ADDRESS_A_V42 "JBeTK2YUWEFTTQvcqEyQoS3poXKjjc1oEP"

BOOST_AUTO_TEST_CASE(address_encode__invoke__version_0__okay_output)
{
    SX_DECLARE_COMMAND(address_encode);
    command.set_ripemd160_argument({ SX_ADDRESS_ENCODE_RIPEMD160_A });
    SX_REQUIRE_OKAY(command.invoke(output, error));
    SX_REQUIRE_OUTPUT(SX_ADDRESS_ENCODE_ADDRESS_A_V0 "\n");
}

BOOST_AUTO_TEST_CASE(address_encode__invoke__version_42__okay_output)
{
    SX_DECLARE_COMMAND(address_encode);
    command.set_version_option(42);
    command.set_ripemd160_argument({ SX_ADDRESS_ENCODE_RIPEMD160_A });
    SX_REQUIRE_OKAY(command.invoke(output, error));
    SX_REQUIRE_OUTPUT(SX_ADDRESS_ENCODE_ADDRESS_A_V42 "\n");
}

BOOST_AUTO_TEST_SUITE_END()