/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_CONVERTER_ICONVERTERCONTROLLER_H
#define MU_CONVERTER_ICONVERTERCONTROLLER_H

#include "modularity/imoduleinterface.h"
#include "types/ret.h"
#include "io/path.h"

namespace mu::converter {
class IConverterController : MODULE_EXPORT_INTERFACE
{
    INTERFACE_ID(IConverterController)
public:
    virtual ~IConverterController() = default;

    virtual muse::Ret fileConvert(const muse::io::path_t& in, const muse::io::path_t& out,
                                  const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false,
                                  const muse::String& soundProfile = muse::String()) = 0;
    virtual muse::Ret batchConvert(const muse::io::path_t& batchJobFile,
                                   const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false,
                                   const muse::String& soundProfile = muse::String()) = 0;

    virtual muse::Ret convertScoreParts(const muse::io::path_t& in, const muse::io::path_t& out,
                                        const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) = 0;

    virtual muse::Ret exportScoreMedia(const muse::io::path_t& in, const muse::io::path_t& out,
                                       const muse::io::path_t& highlightConfigPath = muse::io::path_t(),
                                       const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) = 0;
    virtual muse::Ret exportScoreMeta(const muse::io::path_t& in, const muse::io::path_t& out,
                                      const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) = 0;
    virtual muse::Ret exportScoreParts(const muse::io::path_t& in, const muse::io::path_t& out,
                                       const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) = 0;
    virtual muse::Ret exportScorePartsPdfs(const muse::io::path_t& in, const muse::io::path_t& out,
                                           const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) = 0;
    virtual muse::Ret exportScoreTranspose(const muse::io::path_t& in, const muse::io::path_t& out, const std::string& optionsJson,
                                           const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) = 0;

    virtual muse::Ret exportScoreVideo(const muse::io::path_t& in, const muse::io::path_t& out) = 0;

    virtual muse::Ret updateSource(const muse::io::path_t& in, const std::string& newSource, bool forceMode = false) = 0;
};
}

#endif // MU_CONVERTER_ICONVERTERCONTROLLER_H
