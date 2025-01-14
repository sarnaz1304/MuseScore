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
#ifndef MU_CONVERTER_CONVERTERCONTROLLER_H
#define MU_CONVERTER_CONVERTERCONTROLLER_H

#include <list>

#include "../iconvertercontroller.h"

#include "modularity/ioc.h"
#include "project/iprojectcreator.h"
#include "project/inotationwritersregister.h"
#include "project/iprojectrwregister.h"
#include "context/iglobalcontext.h"

#include "types/retval.h"

namespace mu::converter {
class ConverterController : public IConverterController
{
    INJECT(project::IProjectCreator, notationCreator)
    INJECT(project::INotationWritersRegister, writers)
    INJECT(project::IProjectRWRegister, projectRW)
    INJECT(context::IGlobalContext, globalContext)

public:
    ConverterController() = default;

    muse::Ret fileConvert(const muse::io::path_t& in, const muse::io::path_t& out,
                          const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false,
                          const muse::String& soundProfile = muse::String()) override;
    muse::Ret batchConvert(const muse::io::path_t& batchJobFile,
                           const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false,
                           const muse::String& soundProfile = muse::String()) override;

    muse::Ret convertScoreParts(const muse::io::path_t& in, const muse::io::path_t& out,
                                const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) override;

    muse::Ret exportScoreMedia(const muse::io::path_t& in, const muse::io::path_t& out,
                               const muse::io::path_t& highlightConfigPath = muse::io::path_t(),
                               const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) override;
    muse::Ret exportScoreMeta(const muse::io::path_t& in, const muse::io::path_t& out,
                              const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) override;
    muse::Ret exportScoreParts(const muse::io::path_t& in, const muse::io::path_t& out,
                               const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) override;
    muse::Ret exportScorePartsPdfs(const muse::io::path_t& in, const muse::io::path_t& out,
                                   const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) override;
    muse::Ret exportScoreTranspose(const muse::io::path_t& in, const muse::io::path_t& out, const std::string& optionsJson,
                                   const muse::io::path_t& stylePath = muse::io::path_t(), bool forceMode = false) override;

    muse::Ret exportScoreVideo(const muse::io::path_t& in, const muse::io::path_t& out) override;

    muse::Ret updateSource(const muse::io::path_t& in, const std::string& newSource, bool forceMode = false) override;

private:

    struct Job {
        muse::io::path_t in;
        muse::io::path_t out;
    };

    using BatchJob = std::list<Job>;

    muse::RetVal<BatchJob> parseBatchJob(const muse::io::path_t& batchJobFile) const;

    bool isConvertPageByPage(const std::string& suffix) const;
    muse::Ret convertPageByPage(project::INotationWriterPtr writer, notation::INotationPtr notation, const muse::io::path_t& out) const;
    muse::Ret convertFullNotation(project::INotationWriterPtr writer, notation::INotationPtr notation, const muse::io::path_t& out) const;

    muse::Ret convertScorePartsToPdf(project::INotationWriterPtr writer, notation::IMasterNotationPtr masterNotation,
                                     const muse::io::path_t& out) const;
    muse::Ret convertScorePartsToPngs(project::INotationWriterPtr writer, notation::IMasterNotationPtr masterNotation,
                                      const muse::io::path_t& out) const;
};
}

#endif // MU_CONVERTER_CONVERTERCONTROLLER_H
